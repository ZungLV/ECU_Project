#include "csv_io.h"


#define LINE_BUF_SIZE 1024
#define CSV_PATH      "UI/data.csv"

const char* csv_getString(const char* key)
{
    FILE *fp = fopen(CSV_PATH, "r");
    if (!fp) {
        printf("Can't open file csv");
        return NULL;
    }

    char line[LINE_BUF_SIZE];
    while (fgets(line, sizeof(line), fp)) {
        /* Loại bỏ newline/CR */
        size_t len = strlen(line);
        while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) {
            line[--len] = '\0';
        }

        /* Tách key và phần value tại dấu ',' đầu tiên */
        char *comma = strchr(line, ',');
        if (!comma) {
            continue;
        }
        *comma = '\0';
        char *file_key = line;
        char *file_val = comma + 1;

        if (strcmp(file_key, key) == 0) {
            /* Trả về phần dữ liệu phía sau dấu ',' */
            char *result = (char *)malloc(strlen(file_val) + 1);
            if (!result) {
                printf("Invalid key\n");
                fclose(fp);
                return NULL;
            }
            strcpy(result, file_val);
            fclose(fp);
            return result;
        }
    }

    fclose(fp);
    return NULL;
}

int csv_getInt(const char* key)
{
    char* txt = csv_getString(key);  // lấy chuỗi value từ file CSV
    if (!txt) {
        printf("Invalid value!\n");
        return 0;
    }

    int value = atoi(txt);  // chuyển chuỗi thành số nguyên
    free(txt);              // vì csv_getString cấp phát động
    return value;
}



void csv_setInt(const char *key, int value) {
    FILE *fp = fopen(CSV_PATH, "r");
    if (!fp) {
        printf("Can't open file for reading\n");
        return;
    }

    // Tạm lưu tất cả các dòng trong bộ nhớ
    char **lines = NULL;
    size_t count = 0;
    char line[LINE_BUF_SIZE];

    while (fgets(line, sizeof(line), fp)) {
        /* Loại bỏ newline/CR */
        size_t len = strlen(line);
        while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) {
            line[--len] = '\0';
        }

        /* Tách key và phần value tại dấu ',' đầu tiên */
        char *comma = strchr(line, ',');
        if (comma) {
            *comma = '\0';
            char *file_key = line;

            if (strcmp(file_key, key) == 0) {
                // Tạo dòng mới với giá trị được cập nhật
                snprintf(line, sizeof(line), "%s,%d", file_key, value);
            }
            *comma = ',';  // Phục hồi dòng nếu không khớp
        }

        // Lưu dòng vào mảng
        lines = realloc(lines, sizeof(char *) * (count + 1));
        if (!lines) {
            fclose(fp);
            return;
        }
        lines[count] = strdup(line);
        if (!lines[count]) {
            fclose(fp);
            return;
        }
        count++;
    }
    fclose(fp);

    // Ghi đè lại file với nội dung mới
    fp = fopen(CSV_PATH, "w");
    if (!fp) {
        printf("Can't open file for writing\n");
        return;
    }
    for (size_t i = 0; i < count; i++) {
        fprintf(fp, "%s\n", lines[i]);
        free(lines[i]);
    }
    free(lines);
    fclose(fp);

    return;
}