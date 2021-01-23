from flask import Flask, render_template, redirect, url_for, session
from flask.globals import session
from flask_wtf import FlaskForm
from flask_wtf.recaptcha import validators
from wtforms import StringField, BooleanField, RadioField, TextAreaField, SubmitField
from wtforms.validators import DataRequired

app = Flask(__name__)

app.config['SECRET_KEY'] = 'skfksljflksjfklldsdff'


class InfoForm(FlaskForm):
    name = StringField('Your Name', validators=[DataRequired()])
    adult = BooleanField('Are You 21+')
    gender = RadioField('YOur Gender', choices=[
                        ('male', 'Male'), ('female', 'Female')])
    feedback = TextAreaField()
    submit = SubmitField('Enter the new World')


@app.route('/', methods=['POST', 'GET'])
def home():
    form = InfoForm()
    if form.validate_on_submit():
        session['name'] = form.name.data
        session['adult'] = form.adult.data
        session['gender'] = form.gender.data
        session['feedback'] = form.feedback.data
        return redirect(url_for('form_response'))

    return render_template('home_form.html', form=form)


@app.route('/thankyou')
def form_response():
    return render_template('form_response.html')


app.run(debug=True)
