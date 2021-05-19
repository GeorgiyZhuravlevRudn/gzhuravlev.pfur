first_name=str(input('name of player: '))
second_name=str(input('name of enemy: '))
player = {'name': first_name, 'health': 100, 'damage': 50}
enemy = {'name': second_name, 'health': 100, 'damage': 50}
def attack(p1 ,p2):
    p1['health'] -= p2['damage']
    return player, enemy