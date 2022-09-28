#! Note that you shold open the "Let less secure apps access your account" from the following URL
#! https://www.google.com/settings/security/lesssecureapps

import smtplib
import sys
from smtplib import SMTP



From = 'foruvameasurement@gmail.com'     # Your gmail account for sending email
Password = 'Tzuyu99ON77'           # Your gmail account password
To = 'foruvameasurement@gmail.com'                 # The e-mail address you want to send grabing data to


line = sys.stdin.read()

smtp_server = 'smtp.gmail.com'
smtp_port = 587

smtpObj = smtplib.SMTP(smtp_server, smtp_port)
smtpObj.starttls()
smtpObj.login(From,Password)
to = [To]
msg = line

smtpObj.sendmail(From, to, msg)
smtpObj.quit()