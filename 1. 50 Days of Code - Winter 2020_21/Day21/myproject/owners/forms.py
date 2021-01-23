from flask_wtf import FlaskForm
from wtforms import StringField, SubmitField, IntegerField


class AddForm(FlaskForm):
    id = IntegerField('Enter Puppy ID')
    name = StringField('Owner Name')
    submit = SubmitField("Assign Owner")
