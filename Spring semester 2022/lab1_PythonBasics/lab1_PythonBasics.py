# %% [markdown]
# #### Задание №1                                                       
# Напишите скрипт, который преобразует введенное с клавиатуры вещественное число в денежный формат. Например, число 12,5 должно быть преобразовано к виду «12 руб. 50 коп.». В случае ввода отрицательного числа выдайте сообщение «Некорректный формат!» путем обработки исключения в коде.                               

# %%
money = input("Enter your number: ")
try:
    if float(money) < 0: raise ValueError('Money should be a positive')
    print("{} руб. {} коп.".format(money.split(".")[0], money.split(".")[1].ljust(2, '0')))
except ValueError as e:
    print(e)

# %% [markdown]
# #### Задание №2                                                     
# Написать скрипт, который выводит на экран «True», если элементы программно задаваемого списка представляют собой возрастающую последовательность, иначе – «False».                           

# %%
def isAscending(lst):                                             
    i = 1
    while i < len(lst): 
        if (lst[i] < lst[i - 1]): return bool(0)
        i += 1
    return bool(1)

print(isAscending([1, 2, 3, 4, 5, 6, 7, 8]))    
print(isAscending([6, 2, 5, 4, 5, 6, 7, 8]))

# %% [markdown]
# #### Задание №3                                                        
# Напишите скрипт, который позволяет ввести с клавиатуры номер дебетовой карты (16 цифр) и выводит номер в скрытом виде: первые и последние 4 цифры отображены нормально, а между ними – символы «*» (например, 5123 **** **** 1212).                              

# %%
number = input("Card number: ")
print(number[:4], "**** ****", number[-4:])

# %% [markdown]
# #### Задание №4                                                        
# Напишите скрипт, который разделяет введенный с клавиатуры текст на слова и выводит сначала те слова, длина которых превосходит 7 символов, затем слова размером от 4 до 7 символов, затем – все остальные.                                                        

# %%
print(*sorted(input("Enter text: ").split(), key = len, reverse = True)[0:])

# %% [markdown]
# #### Задание №5                                                        
# Напишите скрипт, который позволяет ввести с клавиатуры текст предложения и сформировать новую строку на основе исходной, в которой все слова, начинающиеся с большой буквы, приведены к верхнему регистру. Слова могут разделяться запятыми или пробелами. Например, если пользователь введет строку «город Донецк, река Кальмиус», результирующая строка должна выглядеть так: «город ДОНЕЦК, река КАЛЬМИУС».                                           

# %%
print(*[item.upper() if item[0].isupper() else item.lower() for item in input("Your text: ").split()])

# %% [markdown]
# #### Задание №6                                                    
# Напишите программу, позволяющую ввести с клавиатуры текст предложения и вывести на консоль все символы, которые входят в этот текст ровно по одному разу.                              

# %%
print(*sorted(list(set(input("Your string: ")))))

# %% [markdown]
# #### Задание №7                                                        
# Напишите скрипт, который обрабатывает список строк-адресов следующим образом: сначала определяет, начинается ли каждая строка в списке с префикса «www». Если условие выполняется, то скрипт должен вставить в начало этой строки префикс «http://», а затем проверить, что строка заканчивается на «.com». Если у строки другое окончание, то скрипт должен вставить в конец подстроку «.com». В итоге скрипт должен вывести на консоль новый список с измененными адресами. Используйте генераторы списков.           

# %%
adresses = ["www.github.com", "tg.org", "stackoverflow.com", "www.govnokod.ru", "www.deezer.fr"]
print(*[item[0:] + ".com" if not item.endswith(".com") else item for item in ["http://" + item[0:] if item.startswith("www") else item for item in adresses]], sep = "\n")

# %% [markdown]
# #### Задание №8                                                        
# Напишите скрипт, генерирующий случайным образом число n в диапазоне от 1 до 10000. Скрипт должен создать массив из n целых чисел, также сгенерированных случайным образом, и дополнить массив нулями до размера, равного ближайшей сверху степени двойки. Например, если в массиве было n=100 элементов, то массив нужно дополнить 28 нулями, чтобы в итоге был массив из 128 элементов (ближайшая степень двойки к 100 – это число 128, к 35 это 64 и т.д.).                                                 

# %%
import random
lst = [random.randint(1,9) for item in range(random.randint(1, 100))]
print(*lst + [0 for item in range(len(lst), 1 << (len(lst) - 1).bit_length())], " len: ", len(lst + [0 for item in range(len(lst), 1 << (len(lst) - 1).bit_length())]))

# %% [markdown]
# #### Задание №9                                                        
# Напишите программу, имитирующую работу банкомата. Выберите структуру данных для хранения купюр разного достоинства в заданном количестве. При вводе пользователем запрашиваемой суммы денег, скрипт должен вывести на консоль количество купюр подходящего достоинства. Если имеющихся денег не хватает, то необходимо напечатать сообщение «Операция не может быть выполнена!». Например, при сумме 5370 рублей на консоль должно быть выведено «5x1000 + 3x100 + 1x50 + 2x10».                                   

# %%
money = {1000 : 10, 500 : 20, 100 : 20, 50 : 20}
dict = {1000 : 0, 500 : 0, 100 : 0, 50 : 0}
num = int(input("money: "))

def meh(rng, sum):
    for item in range(money[rng]):
        if (sum + rng <= num):
            sum += rng
            dict[rng] += 1
    return sum

sum = 0
while sum < num:
    for item in money:
        sum = meh(item, sum)
    if (sum < num):
        print("Error!")
    break
print("{}x1000 + {}x500 + {}x100 + {}x50".format(dict[1000], dict[500], dict[100], dict[50]))

# %% [markdown]
# #### Задание №10
# Напишите скрипт, позволяющий определить надежность вводимого пользователем пароля. Это задание является творческим: алгоритм определения надежности разработайте самостоятельно.

# %%
print("more - better: {}".format(len(list(set(input("password: "))))))

# %% [markdown]
# #### Задание №11
# Напишите генератор frange как аналог range() с дробным шагом. 
# <br>Пример вызова: <br>
# <code>for x in frange(1, 5, 0.1):<br>
#     &nbsp;print(x)</code><br>
# выводит 1 1.1 1.2 1.3 1.4 … 4.9

# %%
def frange(start, end, step):
    while start <= end:
        yield round(start, 3)
        start += step

print(*[step for step in frange(1, 2, 0.1)], sep = ',  ')

# %% [markdown]
# #### Задание №12
# Напишите генератор get_frames(), который производит «оконную декомпозицию» сигнала: на основе входного списка генерирует набор списков – перекрывающихся отдельных фрагментов сигнала размера size со степенью перекрытия overlap.<br>Пример вызова:<br>
# <code>for frame in get_frames(signal, size=1024, overlap=0.5):<br>
# &nbsp;print(frame)</code>

# %%
from scipy.io.wavfile import read, write
import matplotlib.pyplot as plt
import numpy as np
import IPython

def getFrames(sequence, size, overlap):
    result = []
    index = 0
    step = size - int(size * overlap)
    for i in range(0, int(len(sequence) / step)):
        if (index + size > len(sequence)):
            result.append([sequence[item] for item in range(index, len(sequence))])
            break
        else:
            result.append([sequence[item] for item in range(index, index + size)])
            index += step
    yield result

Fs, data = read('jazz.wav')

signal = np.array(*[item for item in getFrames(data[:,0], size = 2048, overlap = 0.4)]).flatten()

write('output.wav', Fs, signal)

plt.figure()
plt.plot(data[:,0])
plt.title("Input")
plt.show()
IPython.display.display(IPython.display.Audio(data[:,0], rate = 48000))

plt.figure()
plt.plot(signal)
plt.title("Output")
plt.show()
IPython.display.display(IPython.display.Audio(signal, rate = 48000))

plt.figure()
plt.plot(data[:,0])
plt.plot(signal)
plt.title("Comparasion")
plt.show()

# %% [markdown]
# #### Задание №13
# Напишите собственную версию генератора enumerate под названием extra_enumerate.<br>Пример вызова:<br>
# <code>for i, elem, cum, frac in extra_enumerate(x):<br>
#  &nbsp;print(elem, cum, frac)</code><br>
# В переменной cum хранится накопленная сумма на момент текущей итерации, в переменной frac – доля накопленной суммы от общей суммы на момент текущей итерации. Например, для списка x=[1,3,4,2] 
# вывод будет таким:<br>
# <code>(1, 1, 0.1) (3, 4, 0.4) (4, 8, 0.8) (2, 10, 1)</code>

# %%
def extraEnumerate(sequence, start=0):
     #----------------------------------------------
     # Calculating the sum of a sequence of elements
     # Why i don't use sum(collection)?
     # cos it doesn't work...
     totalSum = 0
     for elem in sequence:
         totalSum += elem
     #----------------------------------------------

     n = start
     curSum = 0
     for elem in sequence:
         curSum += elem
         frac = curSum / totalSum
         yield n, elem, curSum, frac
         n += 1

for i, elem, sum, frac in extraEnumerate([1, 3, 4, 2]):
    print("({}, {}, {})".format(elem, sum, frac))

# %% [markdown]
# #### Задание №14
# Напишите декоратор non_empty, который дополнительно проверяет списковый результат любой функции: если в нем содержатся пустые строки или значение None, то они удаляются.<br>
# Пример кода:<br>
# <code>@non_empty<br>
# def get_pages():<br>
#  &nbsp;return ['chapter1', '', 'contents', '', 'line1']</code>

# %%
def nonEmpty(func):
    return [item for item in func() if item]

@nonEmpty
def getPages():
    pgs = ['chapter1', '', 'contents', '', 'line1', None]
    print("Input:\n", pgs, "Length = ", len(pgs))
    return pgs 

print("Output:\n", getPages, "Length = ", len(getPages))

# %% [markdown]
# #### Задание №15
# Напишите параметризированный декоратор pre_process, который осуществляет предварительную обработку (цифровую фильтрацию) списка по алгоритму: s[i] = s[i]–a∙s[i–1]. Параметр а можно задать в коде (по умолчанию равен 0.97).
# <br>Пример кода:<br>
# <code>@pre_process(a=0.93)<br>
# def plot_signal(s):<br>
#  &nbsp;for sample in s:<br>
#   &nbsp;&nbsp;print(sample)</code>

# %%
from functools import wraps
import random

def preProcess(a = 0.97):
    def getRes(func):
        @wraps(func)
        def wrapper(sample):
            i = 0
            while (i < len(sample)):
                sample[i] = sample[i] - a * sample[i - 1]
                i += 1
            func(sample)
        return wrapper
    return getRes

@preProcess(a = 0.93)
def plotSignal(s):
    print("Output:\n", *[round(item, 3) for item in s])


sample = [random.randint(1,9) for item in range(random.randint(1, 10))]
print("Input:\n", *sample)
plotSignal(sample)

# %% [markdown]
# #### Задание №16
# Напишите скрипт, который на основе списка из 16 названий футбольных команд случайным образом формирует 4 группы по 4 команды, а также выводит на консоль календарь всех игр (игры должны проходить по средам, раз в 2 недели, начиная с 14 сентября текущего года). Даты игр необходимо выводить в формате
# «14/09/2016, 22:45». Используйте модули random и itertools.

# %%
import random
import calendar
import itertools

teams = [ 'Arsenal',  'Aston Villa', 'Brentford', 'Brighton and Hove Albion', 'Burnley', 'Chelsea',
          'Crystal Palace FC', 'Everton FC', 'Leeds United', 'Leicester City', 'Liverpool',
          'Manchester City', 'Manchester United', 'Newcastle United', 'Norwich City', 'Southampton' ]

def getGroups(iterable, n):
    for i in range(0, len(iterable), n):
        yield iterable[i:i + n]

random.shuffle(teams)

groups = [item for item in getGroups(teams, 4)]

pairs = []

for item in groups:
    for meh in range(0, len(item), 2):
        pairs.append([item[meh], item[meh + 1]])

for i in range(0, len(groups)):
    print("Group #{}: {}".format(i + 1, groups[i]))

for i in range(0, len(pairs)):
    print("Pair #{}: {}".format(i + 1, pairs[i]))


cal = calendar.Calendar(2)
year = [cal.monthdatescalendar(2022, i) for i in range(9, 13)]
weaks = []
for mounth in year:
    for weak in mounth:
        weaks.append(weak)

playdays = []
for i in range(1, len(weaks)):
    if i % 2 == 0:
        playdays.append(weaks[i][0])

for i in range(0, len(pairs)):
    print(playdays[i].strftime("%d/%m/%Y, %H:%M -"), pairs[i][0], "vs", pairs[i][1])


