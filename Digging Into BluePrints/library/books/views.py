from flask_wtf import FlaskForm
from wtforms import StringField, SubmitField
from wtforms.validators import DataRequired


class AddBooks(FlaskForm):
    __tablename__ = 'add_books'
    book_name = StringField('Book Title', validators=[DataRequired()])
    author_name = StringField('Book Title', validators=[DataRequired()])
    isbn_number = StringField('ISBN', validators=[DataRequired()])
    student_id = StringField('Student ID', validators=[DataRequired()])
    add_book = SubmitField('Add Book')


class SearchBooks(FlaskForm):
    __tablename__ = 'search_books'
    book_name = StringField('Book Title', validators=[DataRequired()])
    isbn_number = StringField('ISBN')
    search_book = SubmitField('Search Book')
