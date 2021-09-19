import time
from datetime import datetime


def display_time(time=None):
    if time is None:
        time = datetime.now()
    print(time.strftime('%B %d, %Y %H:%M:%S'))


display_time()
time.sleep(1)
display_time()
time.sleep(1)
display_time()
