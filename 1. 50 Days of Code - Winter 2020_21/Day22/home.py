# from flask_bcrypt import Bcrypt

# bcrypt =  Bcrypt()
# password = 'Sarim@5050'
# hashed_password = bcrypt.generate_password_hash(password= password)

# print(hashed_password)



# check = bcrypt.check_password_hash(hashed_password,'Sarim@5050')
# print(check)

from werkzeug.security import generate_password_hash, check_password_hash
hashed_password = generate_password_hash('Sarim@5050')
print(hashed_password)

is_true_flase = check_password_hash(hashed_password, 'Sarim@5050')
print(is_true_flase)