# Team Members: Muhammad Ahmed Hammad 2024341, Abid Kazmi 2024603, Awais Iftikhar 2024124

import streamlit as st
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import LabelEncoder
from sklearn.linear_model import LinearRegression
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, mean_squared_error, classification_report, confusion_matrix
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt
import pickle

from unicodedata import category

st.title('AutoML Dashboard: A GUI-based Interactive Machine Learning Tool for CSV Data')
st.markdown('### Upload CSV file')

uploaded_file = st.file_uploader("Choose file", type="csv")

if uploaded_file is not None:
    df = pd.read_csv(uploaded_file)
    st.write("Dataset Overview:")
    st.dataframe(df.head())

    st.write("Dataset Description:")
    st.write(df.describe())

    for col in df.columns:
            if df[col].dtype == 'object':
                st.write(df[col].value_counts())

    st.markdown('### Select Features and Target')
    features = st.multiselect("Select Independent Variables (Features)", options=df.columns.tolist())
    target = st.selectbox("Select Dependent Variable (Target)", options=df.columns.tolist())

    if target in features:
        st.error("Error: Target variable cannot be one of the independent variable...")
    elif not features:
        st.error("Error: Must Select at Least one Feature...")
    else:
        # Preprocessing
        st.markdown("### Handle Null Values")
        null_strategy = st.radio("Select strategy for missing values",
                                 ['Fill with mean/median', 'Remove rows', 'Leave as is'])

        if null_strategy == 'Fill with mean/median':
            for col in df.columns:
                if df[col].dtype == 'float64' or df[col].dtype == 'int64':
                    df[col].fillna(df[col].mean(), inplace=True)
                else:
                    df[col].fillna(df[col].mode()[0], inplace=True)

        elif null_strategy == 'Remove rows':
            df.dropna(inplace=True)

        st.write("Cleaned Dataset:")
        st.dataframe(df.head())

        label_encoders = {}

        st.markdown('### Preprocessing Data')
        categorical_columns = df.select_dtypes(include=['object']).columns.tolist()
        for col in categorical_columns:
            le = LabelEncoder()
            df[col] = le.fit_transform(df[col])
            label_encoders[col] = le

        X = df[features]
        Y = df[target]

        test_size = st.slider("Select Test Size (fraction)", 0.1, 0.9, 0.2)

        st.markdown("### Select Model or Clustering Algorithm")


        model = st.selectbox("Select Model",
                             ['Decision Tree', 'Random Forest', 'K-Means Clustering', 'Linear Regression'])

        # Model Training
        X_train, X_test, y_train, y_test = train_test_split(X, Y, test_size=test_size, random_state=42)

        if model == 'Linear Regression':
            model = LinearRegression()
            model.fit(X_train, y_train)
            y_predict = model.predict(X_test)
            st.write(f"R² Score: {model.score(X_test, y_test)}")
            st.write(f"Mean Squared Error: {mean_squared_error(y_test, y_predict)}")

        elif model == 'Decision Tree':
            model = DecisionTreeClassifier()
            model.fit(X_train, y_train)
            y_predict = model.predict(X_test)
            st.write(f"Classification Report:")
            st.dataframe(classification_report(y_test, y_predict, output_dict=True))
            cm = confusion_matrix(y_test, y_predict)
            fig, ax = plt.subplots()
            ax.matshow(cm, cmap='Blues')
            for (i, j), val in np.ndenumerate(cm):
                ax.text(j, i, f'{val}', ha='center', va='center', color='black')
            st.pyplot(fig)

        elif model == 'Random Forest':
            model = RandomForestClassifier()
            model.fit(X_train, y_train)
            y_predict = model.predict(X_test)
            st.write(f"Accuracy: {accuracy_score(y_test, y_predict)}")
            st.write(f"Classification Report:")
            st.dataframe(classification_report(y_test, y_predict, output_dict=True))
            cm = confusion_matrix(y_test, y_predict)
            fig, ax = plt.subplots()
            ax.matshow(cm, cmap='Blues')
            for (i, j), val in np.ndenumerate(cm):
                ax.text(j, i, f'{val}', ha='center', va='center', color='black')
            st.pyplot(fig)

        elif model == 'K-Means Clustering':
            k = st.slider("Select Number of Clusters", 1, 10, 3)
            model = KMeans(n_clusters=k, random_state=42)
            df['Cluster'] = model.fit_predict(X)
            st.write(f"K-Means Clustering Results (k={k}):")
            st.write(df[['Cluster']].head())

            fig, ax = plt.subplots()
            ax.scatter(X.iloc[:, 0], X.iloc[:, 1], c=df['Cluster'], cmap='viridis')
            ax.set_xlabel(X.columns[0])
            ax.set_ylabel(X.columns[1])
            st.pyplot(fig)

        # Output and Dashboard
        st.markdown("### Model Evaluation")
        if model in ['Linear Regression']:
            st.write(f"R² Score: {model.score(X_test, y_test)}")
        elif model in ['Decision Tree', 'Random Forest']:
            st.write(f"Accuracy: {accuracy_score(y_test, y_predict)}")

        st.markdown("### Download Trained Model")
        save_model = st.button('Download Model')
        if save_model:
            with open('model.pkl', 'wb') as f:
                pickle.dump(model, f)
            st.success("Model saved as 'model.pkl' : )")

