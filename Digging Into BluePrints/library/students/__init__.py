from flask import Blueprint, render_template, redirect, url_for
from library.students.views import AddStudents, SearchStudents


students_app = Blueprint('students', __name__,
                         template_folder='templates/students')


# @students_app.route('/')
# def index():
#     return render_template('base.html')


@students_app.route('/addstudents', methods=['GET', 'POST'])
def addstudents():
    form = AddStudents()
    return render_template('addstudents.html', form=form)


@students_app.route('/searchstudents', methods=['GET', 'POST'])
def searchstudents():
    form = SearchStudents()
    return render_template('searchstudents.html', form=form)
