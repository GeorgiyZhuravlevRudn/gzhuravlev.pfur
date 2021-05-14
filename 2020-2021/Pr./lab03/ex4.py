import re
Str_1 = input(' введите строку , содержащую русскоязычный текст: ')
print("The original list : ", Str_1)
out_put = re.findall(r'\bе\w+', Str_1)
print("Слова начинающиеся с 'e' : ", str(out_put))
print("кол-во слов  начинающиеся с 'e' : ", len(out_put))
