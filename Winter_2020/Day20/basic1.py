import os
from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate
from sqlalchemy.orm import backref

app = Flask(__name__)

basedir = os.path.abspath(os.path.dirname(__file__) )
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///'+ os.path.join(basedir, 'db.sqlite')
app.config['SQLALCHEMY_DATABASE_MODIFICATIONS'] = False

db = SQLAlchemy(app)
Migrate(app,db)

class Students(db.Model):
    __tablename__ = 'students'
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.Text)
    department = db.relationship('Department', backref='students', lazy='dynamic')

    def __init__(self,name):
        self.name= name

    def __repr__(self):
        return f'The Sudent name : {self.name}'

class Departments(db.Model):
    __tablename__ = 'departments'
    id = db.Column(db.Integer, primary_key= True)
    dept_name = db.Column(db.Text)
    student_id = db.Column(db.Integer, db.ForeignKey('students.id'))

    def __init__(self, dept_name):
        self.dept_name = dept_name

    def __repr__(self):
        return f'The Department is : {self.dept_name}'