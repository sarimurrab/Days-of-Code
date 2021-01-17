from home import Puppy,  db, Toys, Owner

# one = Puppy('Rufus')
# two = Puppy('Katei')
# db.session.add_all([one,two])
# db.session.commit()

print(Puppy.query.all())


#_____________________________
# one = Toys("Chew Box", 1)
# two = Toys("Ball", 2)
# db.session.add_all([one,two])
# db.session.commit()
# print(Toys.query.all())



#_____________________________
# one = Owner("Sarim",2)
# two = Owner("Sarah",1)
# db.session.add_all([one,two])
# db.session.commit()
# print(Owner.query.all())