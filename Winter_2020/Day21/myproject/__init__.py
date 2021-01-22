from myproject.owners.views import owners_blueprints
from myproject.puppies.views import puppies_blueprint
import os

from sqlalchemy.orm import backref


from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate

app = Flask(__name__)
app.config['SECRET_KEY'] = 'skjfkjdjfksjkdfh'


basedir = os.path.abspath(os.path.dirname(__file__))
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///' + \
    os.path.join(basedir, 'adopt.db')
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
db = SQLAlchemy(app)
Migrate(app, db)


app.register_blueprint(owners_blueprints, url_prefix='/owners')
app.register_blueprint(puppies_blueprint, url_prefix='/puppies')
