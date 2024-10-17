import pyperclip, re, urllib.request, sys

mail = re.compile(r'''([a-zA-Z0-9._%+-]+		#имя пользователя
					  @
					  [a-zA-Z0-9.-]+		#имя домена
					  (\.[a-zA-Z]{2,4})		#остальная часть
					  )''', re.VERBOSE)
https = re.compile(r'^https')
link = re.compile(r'^http')

url = input('Введите ссылку: ')

if (https.search(url)!=None):
	print('Ошибка в ссылке, она защищенная...')
	sys.exit()
else:
	text = str(urllib.request.urlopen(url).read())

matches = []
for groups in mail.findall(text):
	matches.append(groups[0])

links = []
for qq in link.findall(text): #получаем ссылки в первой ссылке
	links.append(qq[0])
for j in len(links):
	text = str(urllib.request.urlopen(links[j]).read())
	for groups in mail.findall(text):
		matches.append(groups[0])


if len(matches)>0:
	pyperclip.copy('\n'.join(matches))
	print('В буфер скопированы все e-mail адреса:')
	print('\n'.join(matches))
else:
	print('E-mail не обнаружено')
