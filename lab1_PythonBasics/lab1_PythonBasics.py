def reverse(string):
    return string[::-1]
print(reverse("test"))
print(reverse("world"))
print(reverse("two worlds or even more"))


def square_sum(numbers):
    return sum([num**2 for num in numbers])
arr = [1, 2, 2]
arr1 = [2, 10, -3]
print(square_sum(arr))
print(square_sum(arr1))



def find_short(s):
    return len(sorted(s.split(" "), key = len)[0])

print(find_short("mmm nice python tt"))
print(find_short("mb some more tests"))
print(find_short("ahhh string never be empty"))
print(find_short("butStringCanBeVeryLong"))

def find_smallest_int(arr):
    return min(arr)

arr = {1, 2, 3, 4, -19}
print(find_smallest_int(arr))


def add_binary(a,b):
    return bin(a+b)[2:]

print(add_binary(1,1))
print(add_binary(0,1))
print(add_binary(1,0))



def meh(string):
    counts = {}
    for c in string.lower():
        if c in counts:
            counts[c] += 1
            return bool(0)
        else:
            counts[c] = 1
    return bool(1)

print(meh('PythonforallPythonMustforall'))
print(meh('tutorialspointfordeveloper'))
print(meh('AABBCC'))
print(meh('ABC'))
print(meh("Dermatoglyphics"))
print(meh(""))
print(meh("moOse"))
