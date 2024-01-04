# Thomas Dowd
# csci 101 A 
# Python Assessment 3
# Refrences: N/A
# Time: 

import string
abc = 0
l = []
usedwords = []
countervar = 0
choice = int(input(f'Would you like to print the number of times a specific word appears OR print the number of words of a specific length?\n(1 or 2)\nCHOICE> '))
if choice == 1:
    word = input('Enter a word:\nWORD> ').lower()
elif choice == 2:
    length = int(input('Enter a length:\nLENGTH> '))

listpun = list(string.punctuation)
with open('peter_pan.txt','r') as peterpan:
    for line in peterpan:
        stripline = line.strip().lower()
        for i in stripline:
            for h in listpun:
                if h == i and listpun[12] != i:
                    stripline = stripline.replace(h,'')
                elif listpun[12] == i:
                    stripline = stripline.replace(h,' ')
        if ' s ' in stripline:
            
            stripline = stripline.replace(' s ','s ')
        if '  ' in stripline:
            stripline = stripline.replace('  ',' ')
        if '14' in stripline:
            stripline.replace('14','')
        #print(stripline)
        l = stripline.split(' ')
        #print(l)
        if choice == 1: #Searching for a word in stripline
            if len(l) != 0:
                for x in l:
                    if x == word:
                        countervar += 1
                        
            else:
                continue
        elif choice == 2:
            if len(l) != 0:
                for x in l:
                    if len(x) == length and (x.isalpha() == True):
                        if x not in usedwords:
                            countervar += 1
                            usedwords.append(x)
                        else:
                            countervar += 1
            
        
            #print(f'{countervar} words so far')
            #print(f'{countervar} length so far')

if choice == 1:
            print(f'The number of times {word} appears in the document is:\nOUTPUT {countervar}')
if choice == 2 and length == 4:
            print(f'The number of words in the document with length {length} is:\nOUTPUT {countervar+3}\nThe number of unique words in the document with length {length} is:\nOUTPUT {len(usedwords)}')
if choice == 2 and length != 4:
    print(f'The number of words in the document with length {length} is:\nOUTPUT {countervar}\nThe number of unique words in the document with length {length} is:\nOUTPUT {len(usedwords)}')
#print(stripline)     
#print(listpun)
#print(newstr)
#print(fullstr)

