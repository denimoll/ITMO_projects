import random

def print_field(field):
    for i in field:
        print('| ', end='')
        for j in i:
            if j != 0:
                print(j, end=' | ')
            else:
                print(' ', end=' | ')
        print()

def check_zero_position(field):
    for i in field:
        for j in i:
            if j == 0:
                return 1
    return 0

def set_number(field):
    if not check_zero_position(field):
        return field, 0
    set_number = random.choice((2, 2,4))
    set_status = 0
    while not set_status:
        random_row = random.randint(0,3)
        random_number = random.randint(0,3)
        number = field[random_row][random_number]
        if not number:
            field[random_row][random_number] = set_number
            set_status = 1
    return field, 1

def left(field):
    def shift(row):
        new_row = []
        for i in row:
            if i != 0:
                new_row.append(i)
        while len(new_row) != 4:
            new_row.append(0)
        return new_row

    change_status = 0
    for num, i in enumerate(field):
        new_row = shift(i)
        for j in range(3):
            if new_row[j] == new_row[j+1]:
                new_row[j] *= 2
                new_row[j+1] = 0
                new_row = shift(new_row)
        if field[num] != new_row:
            change_status += 1
        field[num] = new_row
    return field, change_status

def viceversa(field):
    for num, i in enumerate(field):
        i.reverse()
        field[num] = i
    return field

def right(field):
    field, change_status = left(viceversa(field))
    return viceversa(field), change_status

def rotate(field):
    new_field = [[],[],[],[]]
    for i in field:
        num = 0
        for j in i:
            new_field[num].append(j)
            num += 1
    return new_field

def up(field):
    field, change_status = left(rotate(field))
    return rotate(field), change_status

def down(field):
    field, change_status = right(rotate(field))
    return rotate(field), change_status


# Start Game
start_field = [] # Стартовое поле
for i in range(4):
    start_field.append([0,0,0,0])
field, status = set_number(start_field)  # Задание первого значения
while (status): # Начало игры
    print_field(field)
    act = input('Do up/down/right/left (write only first letter): ')
    while act not in ['u', 'd', 'r', 'l']:
        print('Use one of the correct way')
        act = input('Do up/down/right/left (write only first letter): ')
    if act == 'r':
        field, change_status = right(field)
    if act == 'l':
        field, change_status = left(field)
    if act == 'u':
        field, change_status = up(field)
    if act == 'd':
        field, change_status = down(field)
    if change_status:
        field, status = set_number(field)
