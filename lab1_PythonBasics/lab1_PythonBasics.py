#---------------------------------------------------------------------
# Напишите скрипт, который преобразует введенное с клавиатуры 
# вещественное число в денежный формат. Например, число 12,5 должно 
# быть преобразовано к виду «12 руб. 50 коп.». В случае ввода 
# отрицательного числа выдайте сообщение «Некорректный формат!»
# путем обработки исключения в коде.
#---------------------------------------------------------------------
def Exercise1:
    money = input("Enter your number: ")
    try:
        if float(money) < 0: raise ValueError('Money should be a positive')
        print("{} руб. {} коп.".format(money.split(".")[0], money.split(".")[1].ljust(2, '0')))
    except ValueError as e:
        print(e)
        Exercise1()


#---------------------------------------------------------------------
# Написать скрипт, который выводит на экран «True», если элементы 
# программно задаваемого списка представляют собой возрастающую 
# последовательность, иначе – «False».
#---------------------------------------------------------------------
def Exercise2:
    list = {1, 2, 3, 4, 5, 6, 7, 8}
    wrongList = {6, 2, 5, 4, 5, 6, 7, 8}

def isAscending:



Exercise1()
Exercise2()
