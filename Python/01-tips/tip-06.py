from getpass import getpass

username = input('Username: ')
password = getpass('Password: ')


print('Logging In...')
if password == 'a':
    print(dir(getpass))
    print(help(getpass))
