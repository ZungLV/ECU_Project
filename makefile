# Tên chương trình
TARGET = main

# Các thư mục header
HEADER_DIR = \
    csvlib \
    MCAL/Adc \
    MCAL/Can \
    MCAL/Dio \
    MCAL/Pwm \
    IOHWAB

# Các thư mục nguồn
SOURCES_DIR = \
    . \
    csvlib \
    MCAL/Adc \
    MCAL/Can \
    MCAL/Dio \
    MCAL/Pwm \
    IOHWAB

# Tệp nguồn và object tương ứng
SOURCES = $(foreach dir, $(SOURCES_DIR), $(wildcard $(dir)/*.c))
OBJECTS = $(SOURCES:.c=.o)

# Compiler và cờ biên dịch
CC = gcc
CFLAGS = $(foreach dir, $(HEADER_DIR), -I$(dir)) -Wall -Wextra

# Lệnh liên kết (thêm console mode cho MinGW)
LDFLAGS = -Wl,--subsystem,console

# Quy tắc mặc định
all: $(TARGET)

# Liên kết tạo file thực thi
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

# Biên dịch file .c → .o
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Chạy chương trình
run: $(TARGET)
	./$(TARGET)

# Dọn sạch file .o và chương trình
clean:
	-del /f /q $(subst /,\,$(OBJECTS)) $(TARGET).exe 2>nul || exit 0

# Quy tắc giả
.PHONY: all clean run