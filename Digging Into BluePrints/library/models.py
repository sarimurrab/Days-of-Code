from library import db


class Students(db.Model):
    __tablename__ = 'students'
    id = db.Column(db.Integer, primary_key=True)
    student_name = db.Column(db.String(80), nullable=False)
    student_roll = db.Column(db.Integer, nullable=False)
    student_class = db.Column(db.String(80), nullable=False)
    student_phone = db.Column(db.Integer)
    student_email = db.Column(db.String(80))
    books = db.relationship('Books', backref='issued_to')

    def __init__(self, student_name, student_roll, student_class, student_phone, student_email):
        self.student_name = student_name
        self.student_roll = student_roll
        self.student_class = student_class
        self.student_phone = student_phone
        self.student_email = student_email

    def __repr__(self):
        return '{} , {} , {} , {} , {}'.format(self.student_name, self.student_roll, self.student_class, self.student_phone, self.student_email)


class Books(db.Model):
    __tablename__ = 'books'
    id = db.Column(db.Integer, primary_key=True)
    book_name = db.Column(db.String(80), nullable=False)
    author_name = db.Column(db.String(80), nullable=False)
    isbn_number = db.Column(db.Integer, nullable=False)
    student_id = db.Column(db.Integer, db.ForeignKey('students.id'))

    def __init__(self, book_name, author_name, isbn_number, student_id):
        self.book_name = book_name
        self.author_name = author_name
        self.isbn_number = isbn_number
        self.student_id = student_id

    def __repr__(self):
        return '{} , {} , {} , {} '.format(self.book_name, self.author_name, self.isbn_number, self.student_id)
