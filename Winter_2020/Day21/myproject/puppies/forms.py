from flask_wtf import FlaskForm
from wtforms import StringField, SubmitField, IntegerField


class AddForm(FlaskForm):
    id = StringField('ID')
    name = StringField('Name of Puppy')
    submit = SubmitField('Add Puppy')


class DelForm(FlaskForm):
    id = IntegerField("ID Number of Puppy to be removed: ")
    submit = SubmitField('Delete Puppy')