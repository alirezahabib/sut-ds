import hashlib
import random


def leading_zeros(string, length):
    zeros = 0
    num = int(string, 16)

    for i in range(length):
        if num % 2 == 0:
            zeros += 1
            num //= 2
        else:
            return zeros

    return zeros


def main():
    my_set = set()
    max_leading_zeros = 0
    max_leading_zeros2 = 0

    for i in range(100000):
        n = random.randint(0, 1000000)
        my_set.add(n)
        max_leading_zeros = max(max_leading_zeros,
                                leading_zeros(hashlib.sha256(str(n).encode('utf-8')).hexdigest(), 256))

        max_leading_zeros2 = max(max_leading_zeros2,
                                 leading_zeros(hashlib.sha1(str(n).encode('utf-8')).hexdigest(), 160))

    print(f'The actual value is: {len(my_set)}')
    print(f'Our estimated value is: {round(2 ** ((max_leading_zeros + max_leading_zeros2)/2))}')


if __name__ == '__main__':
    main()
