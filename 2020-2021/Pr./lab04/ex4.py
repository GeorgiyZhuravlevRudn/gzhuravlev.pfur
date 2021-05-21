first_name = str(input('name of player: '))
second_name = str(input('name of enemy: '))
player = {'name': first_name, 'health': 100, 'damage': 50, 'armor': 1.2}
enemy = {'name': second_name, 'health': 100, 'damage': 50, 'armor': 1.2}
def damage_w_armor(p1,p2):
    newdam=p2['damage']//p1['armor']
    return newdam
def attack(p1 ,p2):
    p1['health'] -= damage_w_armor(p1,p2)
    return p1, p2
print(attack(player,enemy))
print(player)
print(enemy)
