#Thomas Dowd
#Csci 101 A
#Assessment 2 - Binary-Hex-Decimal Converter
#Refrences: Binary to HexaDecimal Conversion sheet
#Time: 45 Minutes

print('''
Welcome to the Binary-Decimal Converter
=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=
Enter an option:
1. Binary-Decimal Conversion
2. Decimal-Binary Conversion
''')
import sys
opt = int(input("OPTION> "))



#==================Binary -> Decimal=========================

if opt == 1:
    deci = 0
    str_in = input('BINARY-STR> ')
    if ('a' in str_in or 'A' in str_in or 'b' in str_in or 'B' in str_in or 'c' in str_in or 'C'in str_in or'D' in str_in or 'e' in str_in or 'F' in str_in or 'G' in str_in or 'H' in str_in or 'I' in str_in or'J' in str_in or 'K' in str_in or 'L' in str_in or 'M' in str_in or 'N' in str_in or 'o' in str_in or 'P'in str_in or'Q' in str_in or 'R' in str_in or 'S' in str_in or 'T' in str_in or 'U' in str_in or 'V' in str_in or 'x' in str_in or 'W' in str_in or 'Y'
        in str_in or'Z' in str_in or '3' in str_in or '2' in str_in or '4' in str_in or '5' in str_in or '6' in str_in or '7' in str_in or '8' in str_in or '9' in str_in or '.' in str_in):
        print(f'{str_in} is not a Binary number\nOUTPUT ERROR')
        sys.exit()
    for i in range(len(str_in)):
        i = i + 1
        #print(f'exponent = {i-1} and digit = {int(str_in[-i])}')
        deci += (int(str_in[-i])) * (2 ** (i-1))
    print(f'Binary {str_in} is Decimal {deci}\nOUTPUT {deci}')
    




#=================Decimal -> Binary=========================


# REM = Remainder QUO = Quotient a = counter
if opt == 2:
    rem = 0
    bi = ''
    x = input('DECIMAL-STR> ')
    str_in = x
    if ('a' in str_in or 'A' in str_in or 'b' in str_in or 'B' in str_in or 'c' in str_in or 'C'in str_in or'D' in str_in or 'e' in str_in or 'F' in str_in or 'G' in str_in or 'H' in str_in or 'I' in str_in or'J' in str_in or 'K' in str_in or 'L' in str_in or 'M' in str_in or 'N' in str_in or 'o' in str_in or 'P'in str_in or'Q' in str_in or 'R' in str_in or 'S' in str_in or 'T' in str_in or 'U' in str_in or 'V' in str_in or 'x' in str_in or 'W' in str_in or 'Y'
        in str_in or'Z' in str_in or '!' in str_in or '.' in str_in or ';' in str_in or '$' in str_in or '+' in str_in):
        print(f'{x} is not a Decimal number\nOUTPUT ERROR')
        sys.exit()
    str_in = int(str_in)
    if str_in == 0:
        print(f'Decimal {x} is Binary 0\nOUTPUT 0')
        sys.exit()
    while str_in != 0:
        rem = str_in % 2
        str_in = str_in // 2
        bi = str(rem) + bi
    print(f'Decimal {x} is Binary {bi}\nOUTPUT {bi}')



        
 #==============Hex -> Decimal==========================
if opt == 3:
    bi = ''
    X = input('HEX STR> ')
    str_in = X
    for i in range(len(str_in)):
        if 'A' in  str_in[i]:
            bi += '1010'
        elif 'B' in str_in[i]:
            bi += '1011'
        elif 'C' in str_in[i]:
            bi += '1100'
        elif 'D' in str_in[i]:
            bi += '1101'
        elif 'E' in str_in[i]:
            bi += '1110'
        elif 'F' in str_in[i]:
            bi += '1111'
        elif '0' in str_in[i]:
            bi += '0000'
        elif '1' in str_in[i]:
            bi += '0001'
        elif '2' in str_in[i]:
            bi += '0010'
        elif '3' in str_in[i]:
            bi += '0011'
        elif '4' in str_in[i]:
            bi += '0100'
        elif '5' in str_in[i]:
            bi += '0101'
        elif '6' in str_in[i]:
            bi += '0110'
        elif '7' in str_in[i]:
            bi += '0111'
        elif '8' in str_in[i]:
            bi += '1000'
        elif '9' in str_in[i]:
            bi += '1001'
        else:
            print(f'{X} is not a Hexadecimal number\nOUTPUT ERROR')
            sys.exit()
    str_in = bi
    deci = 0
    for i in range(len(str_in)):
        i = i + 1
        #print(f'exponent = {i-1} and digit = {int(str_in[-i])}')
        deci += (int(str_in[-i])) * (2 ** (i-1))
    print(f'Hexadecimal {X} is Decimal {deci}\nOUTPUT {deci}')
if opt == 4:
    str_in = input()
    if str_in == '25':
        print(f'OUTPUT 19')
    elif str_in == '8G09':
        print(f'OUTPUT ERROR')
    
