from flask import Blueprint, render_template, redirect, url_for
from library.books.views import AddBooks, SearchBooks

books_app = Blueprint('books', __name__, template_folder='templates/books')


# @books_app.route('/')
# def index():
#     return render_template('base.html')


@books_app.route('/addbooks', methods=['GET', 'POST'])
def addbooks():
    form = AddBooks()
    return render_template('addbooks.html', form=form)


@books_app.route('/searchbooks', methods=['GET', 'POST'])
def searchbooks():
    form = SearchBooks()
    return render_template('searchbooks.html', form=form)
