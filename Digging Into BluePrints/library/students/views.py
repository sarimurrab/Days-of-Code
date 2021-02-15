from flask_wtf import FlaskForm
from wtforms import StringField, SubmitField, IntegerField
from wtforms.validators import DataRequired


class AddStudents(FlaskForm):
    __tablename__ = 'add_students'
    student_name = StringField('Student Name', validators=[DataRequired()])
    student_roll = IntegerField('Student Roll', validators=[DataRequired()])
    student_class = StringField('Student Class', validators=[DataRequired()])
    student_phone = IntegerField('Student Phone')
    student_email = StringField('Student Email')
    add_student = SubmitField('Enroll Student')


class SearchStudents(FlaskForm):
    __tablename__ = 'search_students'
    student_name = StringField('Student Name', validators=[DataRequired()])
    student_roll = IntegerField('Student Roll', validators=[DataRequired()])
    search_student = SubmitField('Search Student')
