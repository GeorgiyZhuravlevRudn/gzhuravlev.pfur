month = {'01': 'january', '02': 'february', '03': 'march',
         '04': 'april', '05': 'may', '06': 'june',
         '07': 'july', '08': 'august', '09': 'september',
         '10': 'october', '11': 'november', '12': 'december'}

day = {'01': 'first', '02': 'second', '03': 'third',
       '04': 'fourth', '05': 'fifth', '06': 'sixth',
        '07': 'seventh', '08': 'eighth', '09': 'ninth',
        '10': 'tenth', '11': 'eleventh', '12': 'twelfth',
        '13': ' thirteenth', '14': ' fourteenth', '15': 'fifteenth',
        '16': 'sixteenth', '17': 'seventeenth', '18': 'eighteenth',
        '19': ' nineteenth', '20': 'twentieth', '21': 'twenty first',
        '22': 'twenty second', '23': 'twenty', '24': 'twenty fourth',
        '25': 'twenty fifth', '26': 'twenty sixth', '27': 'twenty seventh',
        '28': 'twenty eighth', '29': 'twenty ninth', '30': 'thirtieth',
        '31': 'thirty first'}

x = input('input date in numeral form with dots(for example 21.02.2021):').split('.')
print("Date: ", month[x[1]], day[x[0]], ',', x[2], ' year.')
