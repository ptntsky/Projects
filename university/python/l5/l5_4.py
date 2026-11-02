db = {
    101: {'name': 'Іван', 'surname': 'Коваль', 'year': 1, 'grades': [5, 4, 2, 5]},
    102: {'name': 'Олена', 'surname': 'Бондар', 'year': 1, 'grades': [5, 5, 5, 5]},
    103: {'name': 'Петро', 'surname': 'Мельник', 'year': 1, 'grades': [3, 4, 4, 3]},
    104: {'name': 'Марія', 'surname': 'Шевченко', 'year': 2, 'grades': [4, 4, 5, 5]},
    105: {'name': 'Андрій', 'surname': 'Ткач', 'year': 2, 'grades': [2, 2, 3, 4]},
    106: {'name': 'Оксана', 'surname': 'Кравець', 'year': 2, 'grades': [5, 4, 4, 5]},
    107: {'name': 'Тарас', 'surname': 'Лисенко', 'year': 3, 'grades': [3, 3, 4, 5]},
    108: {'name': 'Юлія', 'surname': 'Поліщук', 'year': 3, 'grades': [5, 5, 4, 5]},
    109: {'name': 'Роман', 'surname': 'Гнатюк', 'year': 4, 'grades': [2, 3, 3, 4]},
    110: {'name': 'Софія', 'surname': 'Мороз', 'year': 4, 'grades': [4, 5, 5, 5]},
}
cnt = {}
for s in db.values():
    cnt[s['year']] = cnt.get(s['year'], 0) + (2 in s['grades'])
print(cnt)
