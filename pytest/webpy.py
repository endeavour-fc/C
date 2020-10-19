import requests, sys,webbrowser,bs4,os
url='http://xkcd.com'
os.makedirs('xkcd',exist_ok=True)
while not url.endswith('#'):
  print('Downloading page %s...'%url)
  res=requests.get(url)
  res.raise_for_status()
  soup=bs4.BeautifulSoup(res.text)

  comicElem=soup.select('#comic img')
  if comicElem==[]:
    print('Could not find comic image.')
  else:
    comicUrl='http:'+comicElem[0].get('src')
    print('Downloading image %s...'%comicUrl)
    res=requests.get(comicUrl)
    res.raise_for_status()

    imageFile=open(os.path.join('xkcd',os.path.basename(comicUrl)),'wb')
    for chunk in res.iter_content(100000):
      imageFile.write(chunk)
    imageFile.close()

    prevLink=soup.select('a[rel="prev"]')[0]
    url='http://xkcd.com'+prevLink.get('href')
  
print('Done.')

