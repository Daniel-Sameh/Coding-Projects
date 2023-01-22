# The Hangman game developed by Daniel Sameh
import random
animals = ['elephant', 'ant', 'horse', 'butterfly', 'giraffe', 'sloth', 'lion', 'tiger', 'donkey', 'cow', 'rabbit', 'turtle', 'bear', 'snake']
names = ['daniel', 'mostafa', 'mohammed', 'sameh', 'samy', 'youssef', 'fady', 'ayman', 'fatma', 'nancy', 'nada', 'habiba', 'vivian', 'karim', 'sandy', 'ali','mina','maha','peter', 'kirollos', 'joly', 'aml']
countries = ['egypt', 'argantine', 'canada', 'qatar', 'france', 'england', 'australia', 'poland', 'libya', 'morroco', 'jordan', 'brazil']
category = input("What kind of words you want? Enter animals or names or countries:")
if category.lower() == 'animals' or category.lower() == 'animal':
    x = animals[random.randint(0, len(animals)-1)]
elif category.lower() == 'names' or category.lower() == 'name':
    x = names[random.randint(0, len(names)-1)]
else:
    x = countries[random.randint(0, len(countries) - 1)]
man = ['|----O', '|    |', '|   /|\\', '|   / \\', '+-------']
lst = []
for i in x:
    print('_', end=' ')
    lst.append('_')
print(f' {len(x)} letters!\n')
result = True
chance = 5
hang = 0
while result:
    ans = input('Guess a letter in the word: ')

    for i in range(len(x)):
        if ans == x[i]:
            del lst[i]
            lst.insert(i, x[i])

    s = 0
    for i in range(len(x)):
        if ans != x[i]:
            s += 1
    if s == len(x):
        chance -= 1
        print(f'Wrong Answer! {chance} chances remaining')
        for j in range(hang + 1):
            print(man[j])
        hang += 1

    for i in lst:
        print(i, end=' ')

    print('\n')

    if chance == 0:
        result = False
        print('The Man Died :( and you lost!!')
        print(f'The world is {x}')
    if lst.count('_') == 0:
        print('You Saved the man!! :)')
        result = False
