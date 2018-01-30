import smtplib

from email.mime.text import MIMEText
def main():
    ver = False
    while ver == False:
        choice = str(input("1) Check or 2) Send : "))
        if choice == "1":
            check()
        elif choice == "2":
            send()
        else:
            ver = False
def check():
    print("You have 0 new messages.")

def send():
    sub = str(input("Subject: "))
    recipient = str(input("To: "))
    body = str(input("Message:\n"))

    msg = MIMEText(body)
    msg['Subject'] = sub
    msg['From']    = "nathan@nato.io"
    msg['To']      = recipient

    s = smtplib.SMTP('smtp.mailgun.org', 587)

    s.login('postmaster@m.nato.io', '6cd7236d5a705667875af4ee57b33d1f')
    s.sendmail(msg['From'], msg['To'], msg.as_string())
    s.quit()

main()
