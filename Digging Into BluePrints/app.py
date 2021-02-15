from library import app
from library.models import db
from library.books import books_app
from library.students import students_app


@app.route("/")
def index():
    app.register_blueprint(books_app, url_prefix='/books')
    app.register_blueprint(students_app, url_prefix='/students')
    return "<h1> Welcome to Library of Coretava </h1>"


if __name__ == '__main__':
    app.run(debug=True)
