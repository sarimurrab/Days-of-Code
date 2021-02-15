
from flask_migrate import Migrate
from flask_sqlalchemy import SQLAlchemy
import os
from flask import Flask

app = Flask(__name__)

basedir = os.path.abspath(os.path.dirname(__file__))
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///' + \
    os.path.join(basedir, 'store.db')
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
app.config['SECRET_KEY'] = 'ksdfkjsdkfjhskjdfhjshdf'

db = SQLAlchemy(app)

Migrate(app, db)

from library.books import books_app
from library.students import students_app
# Registering the Blueprints



