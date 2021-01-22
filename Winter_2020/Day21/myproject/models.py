from myproject import db

########### Models #######

class Puppy(db.Model):
    __tablename__ = 'puppies'

    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.Integer)
    owner = db.relationship('Owner', backref='puppies', uselist=False)

    def __init__(self, name):
        self.name = name

    def __repr__(self):
        return f"<name: {self.name}"


class Owner(db.Model):
    __tablename__ = 'owner'
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.Text)
    puppy_id = db.Column(db.Integer, db.ForeignKey('puppies.id'))

    def __init__(self, name, puppy_id):
        self.name = name
        self.puppy_id = puppy_id

