#! python3

import sys, webbrowser, pyperclip

# Gather address information
if (len(sys.argv) > 1):
    addr = ' '.join(sys.argv[1:])
else:
    addr = pyperclip.paste()

# Do the search
webbrowser.open('https://www.google.com/maps/search/' + addr)