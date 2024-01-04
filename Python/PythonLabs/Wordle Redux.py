# Thomas Dowd
# Sections 101 A
# Lab 7 - Wordle Redux
# References: N/A
# Time:
import random
def get_word_bank(word_length):
    word_bank = []
    with open("dictionary.txt", 'r', encoding='utf-8') as dictionary:
        for line in dictionary:
            line1 = line.strip()
            if len(line1) == word_length:
                word_bank.append(line1)
    return word_bank
def gen_guess_result(new_guess, secret_word, word_length):
    result_list = []
    for i in range(0,word_length):
        result_list.append('_')
    for i in range(0,len(new_guess)): #X replacer
        if new_guess[i] == secret_word[i]:
            result_list[i] = 'x'
    for i in range(0,len(secret_word)): # O replacer
        for k in range(0,len(new_guess)):
            if new_guess[k] == secret_word[i] and result_list[k] != "x":
                result_list[k] = 'o'
    return result_list

# Recommended function, not required
def get_guess(guess_list, word_length, word_bank):
    ineedabool = False
    while ineedabool == False:
        new_guess = input('GUESS> ')
        new_guess = new_guess.lower()
        if new_guess in guess_list:
            print("Please enter a word you havent guessed before.")
            ineedabool = False
        elif new_guess not in word_bank and len(new_guess) == word_length: ### Prolly gonna have to change shit here
            print('Please enter a real word')
        elif len(new_guess) != word_length:
            print(f'Please enter a {word_length}-letter word.')
            ineedabool = False
        else:
            ineedabool = True
    if ineedabool == True:
        #guess_list.append(new_guess)
        return new_guess
num_wins = 0 
num_losses = 0
num_guesses_allowed = 6
play_again = 'Yes'
if __name__ == '__main__':
    num_wins = 0 
    num_losses = 0
    num_guesses_allowed = 6
    play_again = 'Yes'
    seed = input('Welcome to Wordle!\nEnter a seed to start the random number generator.\nSEED> ')
    random.seed(seed)
    tempbool = False
    if tempbool == False:
        word_length = int(input('Enter a length of word to play with.\nLENGTH> '))
        if word_length >=2 and word_length <= 29:
            tempbool = True
        else:
            tempbool = False
    key =[]
    for i in range(0,word_length):
        key.append('x')
        
    word_bank = get_word_bank(word_length)
    while play_again == 'Yes':
        secret_word = random.choice(word_bank)
        print(f"I've chosen a secret a {word_length}-letter word Make a guess.")
        num_guesses_used = 0
        guess_list = []
        game_result = ''
        while num_guesses_used != num_guesses_allowed:
            new_guess = get_guess(guess_list, word_length, word_bank)
            result_list = gen_guess_result(new_guess,secret_word, word_length)
            num_guesses_used +=1
            #print(num_guesses_used)
            print(f"OUTPUT {' '.join(result_list)}")
            if new_guess == secret_word:
                    game_result = 'Won'
                    num_wins += 1
                    print(f"Game Over.\nCongratulations!\nYou guessed the word '{secret_word}' in {num_guesses_used} guesses!")
                    print(f'OUTPUT {secret_word}')
                    print(f'OUTPUT {game_result}')
                    play_again = input('Would you like to play again?\nCONTINUE> ')
                    break
            if num_guesses_used == num_guesses_allowed and new_guess != secret_word:
                    num_losses += 1
                    game_result = 'Lost'
                    play_again = input(f"Game Over.\nYou were not able to guess the secret word '{secret_word}'.\nOUTPUT {secret_word}\nOUTPUT {game_result}\nWould you like to play again?CONTINUE> ")
print(f'You won {num_wins} times and lost {num_losses} times\nOUTPUT {num_wins}\nOUTPUT {num_losses}')    
