# https://en.wikipedia.org/wiki/Zero-width_joiner

a = 'ab'
b = 'a‍b'

print(a, b, len(a), len(b))

print("1", a == b)
print("2", 'a‍\u200Db' == a)
print("3", 'a\u200Db' == b)
print("4", 'a\u200Db' == 'a‍b')

import unicodedata
for form in ['NFC', 'NFD', 'NFKC', 'NFKD']:
    print(form, unicodedata.normalize(form, a) == unicodedata.normalize(form, b))

eval('b\u200Dreakpoint()')