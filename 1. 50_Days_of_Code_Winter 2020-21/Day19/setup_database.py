from home import db, Puppy

# db.create_all()


sam = Puppy('Puppy 3', 3,"ghhjghj")
tgr = Puppy('Puppy 4', 4,"hhhkhjk")

# print(sam.id)  # None
# print(tgr.id)  # None

db.session.add_all([sam, tgr])
db.session.commit()

# print(sam.id)
# print(tgr.id)


# ##############       READ       #####################

# all_puppies = Puppy.query.all()   # select * from Puppy
# print(all_puppies[0].name)

# first = Puppy.query.get(1)  # read by id 
# print(first.name)

# res = Puppy.query.filter_by(name='Tiger').all()   # where name = "Tiger"
# print(res)



# ##############       create       #####################

# temp = Puppy('Doggo',6)
# db.session.add(temp)
# db.session.commit()

# all_puppies = Puppy.query.all()   # select * from Puppy
# print(all_puppies)


# ##############       update       #####################

# obj = Puppy.query.filter_by(name='Doggo').first()
# obj.name = 'Fluffer'
# db.session.add_all([obj])
# db.session.commit()



# all_puppies = Puppy.query.all()   # select * from Puppy
# print(all_puppies)




# ##############       Delete       #####################

# sam = Puppy.query.get(1)
# db.session.delete(sam)
# db.session.commit()
print("##############       Delete       #####################")
all_puppies = Puppy.query.all()   # select * from Puppy
print(all_puppies)
