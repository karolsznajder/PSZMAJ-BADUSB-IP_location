import smtplib
from email.message import EmailMessage
import time
import requests

res = requests.get('https://ipinfo.io/')
data = res.json()

city = data.get('city', 'Unknown')
postal = data.get('postal', 'Unknown')
region = data.get('region', 'Unknown')
ip = data.get('ip', 'Unknown')
provider = data.get('org', 'Unknown')
location = data.get('loc', 'Unknown')

time.sleep(1)

sender = "twoj_email@gmail.com"
recipient = "odbiorca_email@gmail.com"

message = EmailMessage()
message['From'] = sender
message['To'] = recipient
message['Subject'] = 'Lokalizacja uruchomionego pendriva'

info = (
    f"Wiadomość wysłana z adresu IP: {ip} "
    f"z miasta: {city} {postal} "
    f"o lokalizacji: {location} "
    f"w okolicach regionu: {region} "
    f"dodatkowe info: Dostawca usług sieciowych: {provider}"
)

message.set_content(info)

login = "twoj_email@gmail.com"
password = "twoje_haslo_app"

with smtplib.SMTP_SSL('smtp.gmail.com', 465) as mail_server:
    mail_server.set_debuglevel(1)
    mail_server.login(login, password)
    mail_server.send_message(message)
