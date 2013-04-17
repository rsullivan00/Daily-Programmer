import string
inFile = open("input.txt", 'r')
outFile = open("output.txt", 'w')
vowels = set('aeiouy')
for line in inFile:
	flag = True
	highIndex = 0
	for c in vowels:
		if c not in line:
			flag = False
			break
		else:
			if line.find(c) < highIndex:
				flag = False
				break
			else:
				highIndex = line.find(c)
				if(line.rfind(c) != line.find(c)):
					flag = False
					break
	if flag:
		outFile.write(line)
	
inFile.close()
outFile.close()