import re

def email_ok(s):
    return (s.count('@') == 1 and '.' in s and len(s) - s.rfind('.') > 2 and
            bool(re.fullmatch(r'[\w+-]+(\.[\w+-]+)*@([A-Za-z0-9-]+\.)+[A-Za-z]{2,}', s)))

for e in ('user@mail.com', 'us@er@mail.com', 'user@mail.c', 'user@mail'):
    print(e, email_ok(e))
