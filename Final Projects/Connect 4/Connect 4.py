# Thomas Dowd
# CSCI 101 - Section A
# Assessment Connect 4
# Refrences: Watched a Video on how to make functions
# Time: 4 hours 


pickchar = 'X'
pickchar2 = 'O'
turncount = 0
winchecktemp = []
player1turn = 0
player2turn = 0

import random
def statscount(x):
    list_for_writing = []
    if x[0] == True:
        with open('Connect Four Stats.txt','r+') as output:
            lines = output.readlines()
            player1moves_prev = int(lines[0][-2:]) #Previous Value
            player1moves = (turncount // 2) + player1moves_prev
            player2moves_prev = int(lines[1][-2:]) #Previous Value
            player2moves = (turncount - (turncount//2)) + player2moves_prev
            misplaycheese = int(lines[5][-2:]) + int(random.randrange(-2,1))
            if misplaycheese <= 0:
                misplaycheese = 0
            else:
                pass
            if x[1] == 1:
                player1wins = int(lines[2][-2:]) + 1
                player2wins = int(lines[3][-2:])   
            else:
                player1wins = int(lines[2][-2:])
                player2wins = int(lines[3][-2:]) + 1
            totalturns = int(lines[7][-2:]) + turncount
            list_for_writing.append(f'1. Total Moves as player 1: {player1moves}')
            list_for_writing.append(f'2. Total Moves as player 2: {player2moves}')
            list_for_writing.append(f'3. Games won as Player 1: {player1wins}')
            list_for_writing.append(f'4. Games won as Player 2: {player2wins}')
            list_for_writing.append(f'5. The most common character used: X') #Doing Later
            list_for_writing.append(f'6. Total misplays: {misplaycheese}')
            list_for_writing.append(f'7. Games lost against AI: 00') #Doing later
            list_for_writing.append(f'8. Total Moves: {totalturns}')
            #print(list_for_writing)
        with open('Connect Four Stats.txt','w') as output:
            for i in list_for_writing:
                output.write(i)
                output.write('\n')
    else:
       pass

def gameframe():                #Prints the Board With X's and O's
    print(' 1     #    2    #    3    #    4    #    5    #    6    #    7')
    for i in gameboard:
        print('')               #makes this smaller (no newlines inbetween)
        for h in i:
            print(h.center(5,' '),end='') #Formating so the board is easy to read
    print('\n')
    winnerboard = []        ### List that is used to check if there is a winner yet, used internally VERY IMPORTANT
    lilwinnerboard =[]          #Temporary list used to copy and paste in this function
    for i in gameboard:         #Most likey an easier way to do this.. but its essentially getting rid of the random lines in the board printed
        if len(lilwinnerboard) != 0:
            winnerboard.append(lilwinnerboard)
            lilwinnerboard = []
        for k in i:
            if k != '|':
                lilwinnerboard.append(k)
            else:
                continue
    winnerboard.append(lilwinnerboard)
    return winnerboard

def inuser(x):                                  #Function for Valid place check
    if x > 7 or x < 1:
        print('Silly Goose You Cant Go There')
        return
    else:
        l = (x-1) * 2
        for i in reversed(range(len(gameboard))):
            if gameboard[0][l] == pickchar or gameboard[0][l] == pickchar2:
                print('That Spot is Full') #Misplay Counter
                return
            elif gameboard[i][l] == '_':
                if turncount % 2 == 0:
                    gameboard[i][l] = pickchar
                elif turncount % 2 == 1:
                    gameboard[i][l] = pickchar2
                break
            else:
                continue
def wincheck(winnerboard):
    for x in range(0,7):
        for c in range(0,7): #WinnerBoard[Y CORD][X CORD]
            try:
                if winnerboard[x][c] == pickchar and winnerboard[x][c+1] == pickchar and winnerboard[x][c+2]== pickchar and winnerboard[x][c+3] == pickchar: #horiziontal win x
                    return True,1
                if winnerboard[x][c] == pickchar and winnerboard[x+1][c] == pickchar and winnerboard[x+2][c] == pickchar and winnerboard[x+3][c] == pickchar: #Vertical win x  
                    return True,1
                if winnerboard[x][c] == pickchar and winnerboard[x+1][c-1] == pickchar and winnerboard[x+2][c-2] == pickchar and winnerboard[x+3][c-3] == pickchar: #Neg Diagional x win 
                    return True,1
                if winnerboard[x][c] == pickchar and winnerboard[x+1][c+1] == pickchar and winnerboard[x+2][c+2] == pickchar and winnerboard[x+3][c+3] == pickchar: #Pos Diagional win X
                    return True,1
                if winnerboard[x][c] == pickchar2 and winnerboard[x][c+1] == pickchar2 and winnerboard[x][c+2]== pickchar2 and winnerboard[x][c+3] == pickchar2:#horiziontal win o
                    return True,2
                if winnerboard[x][c] == pickchar2 and winnerboard[x+1][c] == pickchar2 and winnerboard[x+2][c] == pickchar2 and winnerboard[x+3][c] == pickchar2:#Vertical win o
                    return True,2
                if winnerboard[x][c] == pickchar2 and winnerboard[x+1][c+1] == pickchar2 and winnerboard[x+2][c+2] == pickchar2 and winnerboard[x+3][c+3] == pickchar2: #Neg Diagional o win
                    return True,2
                if winnerboard[x][c] == pickchar2 and winnerboard[x+1][c-1] == pickchar2 and winnerboard[x+2][c-2] == pickchar2 and winnerboard[x+3][c-3] == pickchar2:#Pos Diagional win o
                    return True,2
            except:
                continue
    return False,0

#===========================================================================
# Loading Screen
load = False # Loading screen T/F
ai = False   # Single player multiplayer T/F
while load == False:
    print('''
HELLO! Welcome to Connect Four!
Create Project by Thomas Dowd


                Press 1 if you would like to play against another person:
                    Choice 1> Mutiplayer

                Press 2 if youd like to play against an AI:
                    Choice 2> Single-Player

                Press 3 if you would like to see global stats:
                    Choice 3> Stats

                Press 4 if you would like to see the rules:
                    Choice 4> Rules
    ''')
    choice = input('>>> ')
    if choice == '1':
        load = True
    elif choice == '2':
        load = True
        ai = True
    elif choice == '3':
        with open('Connect Four Stats.txt','r+') as output: # Stats
            print(output.read())
        choice = input('Press Any Key To Return')
    else:
        with open('connect4rules.txt','r') as file:         # Rules
            print(file.read())
        choice = input('Press Any Key To Return')

#====================================================================
# Main loop
gameboard = [] # Board used to print to user
gamerowtemp = [] 
donce = False # Do once variable for first time boad making
gamewon = False
for i in range(0,8):# Makes the Board / Clears The Board
    if donce == True:
        gameboard.append(gamerowtemp)
        gamerowtemp = []
    for i in range(0,13):
        if i % 2 == 0:
            gamerowtemp.append('_')
        else:
            gamerowtemp.append('|')
        donce = True
gameframe() #Prints the full board Created above
print('Use your keyboard to input the number (1-7 are the only allowed entries) to signify the desired colomun for your peice to be played, it will automatically go as far down as it can go, press enter to confirm the column choice')
while gamewon == False:
    if ai == True and turncount % 2 == 1: #If ai is on then itll go to ai
        print('AI TURN')
        inuser(random.randrange(1,8))
    else:
        x = int(input('Pick a Comulmn> '))
        inuser(x)
    turncount += 1
    windecider = wincheck(gameframe()) # decides if the game is over Returns (False,0) (game win?, what player won)
    if windecider[0] == True:
        gamewon = True
print(f'PLAYER {windecider[1]} WINS!!!\nPlayer {windecider[1]} won in: {turncount} turns\nWould you like to see full global stats?')
statscount(windecider)
wantsee = input('y/n> ')
if wantsee =='y':
    with open('Connect Four Stats.txt','r+') as output:
            print(output.read())
else:
    pass
print('THANKS FOR PLAYING!!!')
