import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText



def ooghls(code):
    to_mail = "svbudygin@yandex.ru"
    sender = "pokerdsba@gmail.com"
    server = smtplib.SMTP("smtp.gmail.com", 587)
    server.starttls()
    try:
        msg = MIMEMultipart()
        server.login(sender, "fppf vgks ikao gitj")
        msg["From"] = sender
        msg["To"] = to_mail
        msg.attach(MIMEText(str(code)))
        msg["Subject"] = "Mail confirmation"
        server.sendmail(sender, to_mail, msg.as_string())
        return "The message was sent successfully!"
    except Exception as _ex:
        return f"{_ex}\nCheck your login or password please!"

if __name__ == "__main__":
    ooghls("ppppppp")