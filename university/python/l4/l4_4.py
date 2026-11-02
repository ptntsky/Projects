s, ch = input('Рядок: '), input('Символ: ')
print(''.join(ch if p == 's' else c for p, c in zip(' ' + s, s)))
