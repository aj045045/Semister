import json
import os
import io
import base64
import matplotlib.pyplot as plt

class JSONHandler:
    """
    Class use to handle JSON Data in `data.json` file
    
    This class is use to do operation on data.json file for registration and login
    """
    def __init__(self):
        """
        Variable Allocation 
        """
        self.__file_path = "data.json"
        self.__userName = None
        self.__emailId = None
        self.__password = None
        self.__existing_data = []  # Initialize __existing_data

    @property
    def _userName(self):
        """
        Getter method for user name method
        """
        return self.__userName

    @_userName.setter
    def _userName(self, value):
        """
        Setter method for user name
        """
        self.__userName = value

    @property
    def _emailId(self):
        """
        Getter method for email Id
        """
        return self.__emailId

    @_emailId.setter
    def _emailId(self, value):
        """
        Setter method for email Id
        """
        self.__emailId = value

    @property
    def _password(self):
        """
        Getter Method for password
        """
        return self.__password

    @_password.setter
    def _password(self, value):
        """
        Setter method for password
        """
        self.__password = value

    @classmethod
    def __set_data(cls, userName, emailId, password):
        """
        Setter method for create a dict of user 
        """
        return {
            "userName": userName,
            "emailId": emailId,
            "password": password
        }

    def print_value(self) -> str:
        """
        Convert json data into dict
        """
        data = self.__set_data(self._userName, self._emailId, self._password)
        return json.dumps(data)  # Return as a JSON string

    def read_file(self):
        """
        Read file from `data.json`
        """
        if not os.path.exists(self.__file_path):
            raise FileNotFoundError(f"The file {self.__file_path} does not exist.")
        try:
            with open(self.__file_path, 'r') as json_file:
                self.__existing_data = json.load(json_file)
            return self.__existing_data
        except json.JSONDecodeError as e:
            print(f"Error decoding JSON in file {self.__file_path}: {e}")
            self.__existing_data = []
            return self.__existing_data
            
    def write_file(self):
        """
        Write json data to file `data.json`
        """
        new_entry = self.__set_data(self.__userName, self.__emailId, self.__password)
        if isinstance(self.__existing_data, list):
            if any(entry['emailId'] == self.__emailId for entry in self.__existing_data):
                print(f"Email Id '{self.__emailId}' already exists. Skipping write.")
            else:
                self.__existing_data.append(new_entry)
                
        with open(self.__file_path, 'w') as json_file:
            json.dump(self.__existing_data, json_file, indent=4)



class ImagePlot:
    """
    Class for creating and encoding plots using Matplotlib.

    This class provides methods to generate plots and convert them 
    to base64 encoded format for easy storage or transmission.
    """
    
    @staticmethod
    def plot_image(plot_func,*args):
        """
        Generate a plot and return it as a base64 encoded string.

        This method executes a provided plotting function, 
        configures the plot's appearance, and encodes the result 
        in base64 format for easy transfer.

        Parameters:
            plot_func (callable): A function that creates the plot.
            title (str): The title of the plot. Defaults to 'Plot'.
            xlabel (str, optional): The label for the X-axis. Defaults to 'X-axis'.
            ylabel (str, optional): The label for the Y-axis. Defaults to 'Y-axis'.

        Returns:
            str: A base64 encoded string representing the generated plot.
        """
        plt.figure(figsize=(12, 8))
        plot_func(*args)
        
        # Save the plot to a BytesIO object
        buf = io.BytesIO()
        plt.savefig(buf, format='png')
        plt.close() 
        buf.seek(0)
        img_base64 = base64.b64encode(buf.read()).decode('utf-8')
        return img_base64
