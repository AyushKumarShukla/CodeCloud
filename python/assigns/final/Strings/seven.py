def separateEmail(email):
    loc = email.find('@')
    if loc==-1 or '.' not in email:
        return None,None
    else:
        username=email[:loc]
        domain=email[loc+1:]
        return username,domain

email = input("Enter Email Address: ")
username,domain = separateEmail(email)
print(f"Username:{username}\nDomain:{domain}")

