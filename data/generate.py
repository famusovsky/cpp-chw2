import random

# Функция для генерации случайного текста из бинарного алфавита
def generate_bin_text(length):
    alphabet = ['0', '1']
    return ''.join(random.choices(alphabet, k=length))

def generate_quad_text(length):
    alphabet = ['0', '1', '2', '3']
    return ''.join(random.choices(alphabet, k=length))

# Генерация бинарного текста на 10000 символов и запись его в файл "bin_text_10000.txt"
bin_text_10000 = generate_bin_text(10000)
with open('texts/bin_text_10000.txt', 'w') as f:
    f.write(bin_text_10000)

# Генерация бинарного текста на 100000 символов и запись его в файл "bin_text_100000.txt"
bin_text_100000 = generate_bin_text(100000)
with open('texts/bin_text_100000.txt', 'w') as f:
    f.write(bin_text_100000)

# Генерация квадричного текста на 10000 символов и запись его в файл "quad_text_10000.txt"
quad_text_10000 = generate_quad_text(10000)
with open('texts/quad_text_10000.txt', 'w') as f:
    f.write(quad_text_10000)

# Генерация квадричного текста на 100000 символов и запись его в файл "quad_text_100000.txt"
quad_text_100000 = generate_quad_text(100000)
with open('texts/quad_text_100000.txt', 'w') as f:
    f.write(quad_text_100000)