import pickle
import json
my_favourite_group={
    'name': 'Baroque composers',
    'tracks': ['Bach, partita no5 praeludium BWV829','Bach, toccata in e-moll BWV 914'],
    'Albums':[{'name':'BWV829','year':'1730'}{'name':'BWV914','year':'1710'}]
}
my_f_g=pickle.dumps(my_favourite_group)
print(type(my_f_g))

with open('song.json','w', encoding='utf-8') as f:
    json.dump(my_favourite_group, f)

with open('song.pickle','wb') as f:
    pickle.dump(my_favourite_group, f)