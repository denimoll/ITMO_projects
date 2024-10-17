import sys

board = {'tl': ' ', 'tm': ' ', 'tr': ' ',
		 'ml': ' ', 'mm': ' ', 'mr': ' ',
		 'll': ' ', 'lm': ' ', 'lr': ' '}

def printboard(board):
	print(board['tl'] + '|' + board['tm'] + '|' + board['tr'])
	print('-+-+-')
	print(board['ml'] + '|' + board['mm'] + '|' + board['mr'])
	print('-+-+-')
	print(board['ll'] + '|' + board['lm'] + '|' + board['lr'])

def check(board):
	chain = [0,0,0,0,0,0,0,0,0]
	k = 0
	for i in board.values():
		if i == 'X':
			a = 1
		elif i == 'O':
			a = 0
		else:
			a = 3
		chain[k] = a
		k += 1
	winner(chain)

def winner(chain):
	good_chain = [[1,1,1,2,2,2,2,2,2],[2,2,2,1,1,1,2,2,2],[2,2,2,2,2,2,1,1,1],
				 [1,2,2,1,2,2,1,2,2],[2,1,2,2,1,2,2,1,2],[2,2,1,2,2,1,2,2,1],
				 [1,2,2,2,1,2,2,2,1],[2,2,1,2,1,2,1,2,2]]
	count = 0
	bool = False
	for i in range(8):
		if count == 3:
				bool = True
				break	
		count = 0
		for k in range(9):
			if chain[k] == good_chain[i][k]:
				count += 1

	if bool == True:
		print('\n\n\n\n**************\nПобедитель: X\n**************')
		printboard(board)
		sys.exit()
	
	good_chain = [[0,0,0,2,2,2,2,2,2],[2,2,2,0,0,0,2,2,2],[2,2,2,2,2,2,0,0,0],
				 [0,2,2,0,2,2,0,2,2],[2,0,2,2,0,2,2,0,2],[2,2,0,2,2,0,2,2,0],
				 [0,2,2,2,0,2,2,2,0],[2,2,0,2,0,2,0,2,2]]
	count = 0
	bool = False
	for i in range(8):
		if count == 3:
				bool = True
				break	
		count = 0
		for k in range(9):
			if chain[k] == good_chain[i][k]:
				count += 1

	if bool == True:
		print('\n\n\n\n**************\nПобедитель: O\n**************')
		printboard(board)
		sys.exit()
	
turn = 'X'

for i in range(9):
	printboard(board)
	move = input('Ход '+ turn+ ': ')
	while 1:
		try:
			if board[move] == ' ':
				board[move] = turn
				break
			else:
				move = input('Ячейка уже занята, введите новое значение: ')
		except KeyError:
			move = input('Ошибка: неправильное значение, введите новое: ')
	check(board)
	if turn == 'X':
		turn = 'O'
	else:
		turn = 'X'
check(board)
