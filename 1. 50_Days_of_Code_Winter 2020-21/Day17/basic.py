from flask import Flask, render_template
from flask_wtf import FlaskForm
from wtforms import StringField, SubmitField

app = Flask(__name__)
app.config['SECRET_KEY'] = 'heremysecretkey'


class Infoform(FlaskForm):

    breed = StringField('Name of Breed')
    submit = SubmitField('Submit')


@app.route('/', methods=['POST', 'GET'])
def form():

    form = Infoform()

    breed = "None"
    # if form.validate_on_submit:
    breed = form.breed.data
    form.breed.data = ''
    return render_template('index.html', form=form, breed=breed)


app.run(debug=True)
