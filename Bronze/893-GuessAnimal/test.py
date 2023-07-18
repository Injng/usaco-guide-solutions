import requests


import urllib3
urllib3.disable_warnings(urllib3.exceptions.InsecureRequestWarning)

Target_address = '143.254.0.17'
# 10922, 11260, 11578

ids = []
for i in range(0,200000):
  if i % 100 == 0:
    print('Testing ID: {}'.format(i))

  id_probe = requests.get('https://' + Target_address + '/forms/embed.php?id={}'.format(i),verify=False)

  if id_probe.text != 'This is not valid form URL.':

    id = i; ids.append(id);


print(ids)
