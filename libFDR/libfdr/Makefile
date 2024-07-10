# Derleyici
CC = gcc
# Derleme bayrakları
CFLAGS = -O
# Nesne dosyaları
OBJS = dllist.o fields.o jval.o jrb.o
# Hedef dosyası
TARGET = libfdr.a

# Hedef: Tümü
all: $(TARGET)

# Hedef: Kütüphane dosyası oluşturma
$(TARGET): $(OBJS)
	ar ru $@ $^
	ranlib $@

# Hedef: Nesne dosyalarını oluşturma
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Hedef: Temizlik
clean:
	rm -f $(TARGET) $(OBJS)