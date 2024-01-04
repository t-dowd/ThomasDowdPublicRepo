# Thomas Dowd, and Kevin Cano
# Csci 101 Section A and KEV I NEED UR SECTION 
# Python lab 5
# Refrences: N/A
# Time: 90 minutes

countervar = 0
rows = int(input('rows> '))
col = int(input('colums> '))
lilmat = [] # List comparable to Rows
bigmat = [] # Arrary of inputted letters
tray = [] # Coords of the T's in the Bigmat
sray = [] # Coords of the S's in the Bigmat
ump = [] # Unpowered Houses

# Puts in put into an array #
for j in range(rows): 
    x = input(f'ROW{j}> ').split(' ')
    bigmat.append(x)
# Appends the Coordinates of the Telsa or supertesla to a list so we can keep track of them properly #
for j in range(rows):
    for i in range(col):
        x = bigmat[j][i]
        if x == 'T':
            tray.append([j,i]) # List of coordinates for the Teslas, T-Array = tray!
        elif x == 'S':         # List of coordinates for the Supertesla, S-Array = sray!
            sray.append([j,i]) 

acceptable_col_val = []
acceptable_row_val =[]  #List of 

for x in range(col):
    acceptable_col_val.append(x)
for y in range(rows):
    acceptable_row_val.append(y)

for coord in tray:
    if (coord[0] - 1) in acceptable_row_val: #DIRECT UP
        bigmat[coord[0]-1][coord[1]] = 'P'
    if (coord[0] +1) in acceptable_row_val: #direct Down
        bigmat[coord[0]+1][coord[1]] = 'P'
    if (coord[1] +1) in acceptable_col_val: #direct right
        bigmat[coord[0]][coord[1]+1] = 'P'
    if (coord[1] -1) in acceptable_col_val: #DSirect Left
        bigmat[coord[0]][coord[1]-1] = 'P'
    if (coord[0] -1) in acceptable_row_val and (coord[1]+1) in acceptable_col_val: #diagional Right top
        bigmat[coord[0]-1][coord[1]+1] = 'P' 
    if (coord[0] -1) in acceptable_row_val and (coord[1]-1) in acceptable_col_val: #diagional left top
        bigmat[coord[0]-1][coord[1]-1] = 'P' 
    if (coord[0]+1) in acceptable_row_val and (coord[1]+1) in acceptable_col_val: # Diagional Right Bot
        bigmat[coord[0]+1][coord[1]+1] = 'P'
    if (coord[0]+1) in acceptable_row_val and (coord[1]-1) in acceptable_col_val: #Diagional Left Bot
        bigmat[coord[0]+1][coord[1]-1] = 'P'

for coord in sray:
    if (coord[0] - 1) in acceptable_row_val: #DIRECT UP
        bigmat[coord[0]-1][coord[1]] = 'P'
    if (coord[0] -2) in acceptable_row_val: #Direct up by 2
        bigmat[coord[0]-2][coord[1]] = 'P'
    if (coord[0] +1) in acceptable_row_val: #direct Down
        bigmat[coord[0]+1][coord[1]] = 'P'
    if (coord[0] +2) in acceptable_row_val: #direct Down by 2
        bigmat[coord[0]+2][coord[1]] = 'P'
    if (coord[1] +1) in acceptable_col_val: #direct right
        bigmat[coord[0]][coord[1]+1] = 'P'
    if (coord[1] +2) in acceptable_col_val: #direct right by 2
        bigmat[coord[0]][coord[1]+2] = 'P'
    if (coord[1] -1) in acceptable_col_val: # Direct Left
        bigmat[coord[0]][coord[1]-1] = 'P'
    if (coord[1] -2) in acceptable_col_val: # Direct Left By 2
        bigmat[coord[0]][coord[1]-2] = 'P'
    if (coord[0] -1) in acceptable_row_val and (coord[1]+1) in acceptable_col_val: #diagional Right top
        bigmat[coord[0]-1][coord[1]+1] = 'P'
    if (coord[0] -1) in acceptable_row_val and (coord[1]+1) in acceptable_col_val: #diagional Right top by 2
        bigmat[coord[0]-2][coord[1]+2] = 'P'
    if (coord[0] -1) in acceptable_row_val and (coord[1]+2) in acceptable_col_val: # Right Rook top by 2
        bigmat[coord[0]-1][coord[1]+2] = 'P'
    if (coord[0] +1) in acceptable_row_val and (coord[1]+2) in acceptable_col_val: # Right Rook bottom by 2
        bigmat[coord[0]+1][coord[1]+2] = 'P'
    if (coord[0] -2) in acceptable_row_val and (coord[1]-2) in acceptable_col_val: #diagional left top by 2
        bigmat[coord[0]-2][coord[1]-2] = 'P' 
    if (coord[0] -1) in acceptable_row_val and (coord[1]-2) in acceptable_col_val: #Rook left top by two
        bigmat[coord[0]-1][coord[1]-2] = 'P' # Left # Upper Rook #by 2
    if (coord[0] +1) in acceptable_row_val and (coord[1]-2) in acceptable_col_val: #Rook left lower by two
        bigmat[coord[0]+1][coord[1]-2] = 'P'
    if (coord[0]+2) in acceptable_row_val and (coord[1]+2) in acceptable_col_val: # Diagional Right Bot by 2
        bigmat[coord[0]+2][coord[1]+2] = 'P'
    if (coord[0]+2) in acceptable_row_val and (coord[1]-2) in acceptable_col_val: #Diagional Left Bot by 2
        bigmat[coord[0]+2][coord[1]-2] = 'P'
    if (coord[0] -1) in acceptable_row_val and (coord[1]-1) in acceptable_col_val: #diagional left top
        bigmat[coord[0]-1][coord[1]-1] = 'P' 
    if (coord[0]+1) in acceptable_row_val and (coord[1]-1) in acceptable_col_val: #Diagional Left Bot
        bigmat[coord[0]+1][coord[1]-1] = 'P'
    if (coord[0]+1) in acceptable_row_val and (coord[1]+1) in acceptable_col_val: # Diagional Right Bot
        bigmat[coord[0]+1][coord[1]+1] = 'P'
    if (coord[0]+2) in acceptable_row_val and (coord[1]-1) in acceptable_col_val: 
        bigmat[coord[0]-2][coord[1]-1] = 'P'
    if (coord[0]+2) in acceptable_row_val and (coord[1]+1) in acceptable_col_val: 
        bigmat[coord[0]+2][coord[1]-1] = 'P'
    if (coord[0]-2) in acceptable_row_val and (coord[1]+1) in acceptable_col_val: 
        bigmat[coord[0]-2][coord[1]+1] = 'P'
    if (coord[0]+2) in acceptable_row_val and (coord[1]+1) in acceptable_col_val: 
        bigmat[coord[0]+2][coord[1]+1] = 'P'


print(bigmat)     

for i in range(rows):
    for h in range(col):
        if bigmat[i][h] == 'b':
            countervar += 1
            l = [i,h]
            ump.append(l)
if len(ump) == 0:
    print('ALL BUILDINGS ARE POWERED\nOUTPUT True')
else:
    print(f'Not all buildings are powered!\nOUTPUT False\nThe following buildings are not powered\nOUTPUT{ump}')

print(bigmat)